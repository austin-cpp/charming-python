/*
 * task.i
 * ~~~~~~
 *
 * Copyright (c) 2015 Tanner Sansbury (twsansbury at gmail dot com)
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

%include <std_string.i>
%include <std_shared_ptr.i>

/* Use shared ownership for sample::task. */
%shared_ptr(sample::task);

namespace sample {

/* Rename task to Task based on Python naming conventions. */
%rename(Task) task;

/* Expose the overloaded get and set functions for title and completed
 * as properties.  This requires defining the class, extending it, then
 * providing custom implementations for the wrapped hooks.  As std::string
 * is a non-POD type, it will require additional indirection.
 */

class task
{
public:
  task(std::string, bool);
};

%extend task
{
  /* Create python private methods. */
  std::string _get_title();
  void _set_title(std::string);

  /* Inject python code into the proxy that has Python setup the 
   * properties. */
  %pythoncode %{
    __swig_getmethods__["title"] = _get_title
    __swig_setmethods__["title"] = _set_title
    if _newclass: title = property(_get_title, _set_title)
  %}

  bool completed;
};

} /* namespace sample */

/** Code injected into wrapping as-is. */
%{
  #include <memory> // std::shared_ptr
  #include <sample/task.hpp>

  /* Implement properties.  Note the double underscore required for implementing
   * the Python 'private' methods. */
  std::string sample_task__get_title(sample::task* obj)
  {
    return obj->title();
  }

  void sample_task__set_title(sample::task* obj, std::string value)
  {
    obj->title(value);
  }

  bool sample_task_completed_get(sample::task* obj)
  {
    return obj->completed();
  }

  void sample_task_completed_set(sample::task* obj, bool value)
  {
    obj->completed(value);
  }
%}