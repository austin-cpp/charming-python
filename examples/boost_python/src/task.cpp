//
// task.cpp
// ~~~~~~~~
//
// Copyright (c) 2015 Tanner Sansbury (twsansbury at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost/python.hpp>
#include <sample/task.hpp>

namespace py_sample {

namespace {

bool task_get_completed(sample::task& self)
{
  return self.completed();
}

} // namespace

void init_task()
{
  namespace python = boost::python;

  // Expose task_list.
  python::class_<sample::task,
        std::shared_ptr<sample::task> // Holding type.
      >("Task", // Python class name.
        python::init<std::string, bool>()) // Constructor.
    // Static-cast required when taking address of overloaded function.
    .add_property("title",
      static_cast<std::string (sample::task::*)() const>(&sample::task::title),
      static_cast<void (sample::task::*)(std::string)>(&sample::task::title))
    // Non-member (named and anonymous) functions can be used too.
    .add_property("completed",
      &task_get_completed,
      +[](sample::task& self, bool value) { self.completed(value); })
    ;

  // Expose shared_ptr as a pointer.
  python::register_ptr_to_python<std::shared_ptr<sample::task>>();
}

} // namespace py_sample
