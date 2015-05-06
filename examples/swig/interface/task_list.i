/*
 * task_list.i
 * ~~~~~~~~~~
 *
 * Copyright (c) 2015 Tanner Sansbury (twsansbury at gmail dot com)
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

%include <std_list.i>

%template(tasks) std::list<std::shared_ptr<sample::task>>;

/* Rename to Python naming conventions. */
%rename(TaskList) sample::task_list;
%include <sample/task_list.hpp>

namespace sample {

/* task_list uses a factory method for construction, so extend the wrapper
 * with a constructor that will then be implemented in terms of the factory
 * method. */
%extend task_list
{
  task_list();
};

} // namespace sample

/** Code injected into wrapping as-is. */
%{
  #include <sample/task_list.hpp>

  sample::task_list* new_sample_task_list()
  {
    return sample::task_list::create();
  }
%}
