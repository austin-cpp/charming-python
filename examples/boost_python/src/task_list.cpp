//
// task_list.cpp
// ~~~~~~~~~~~~
//
// Copyright (c) 2015 Tanner Sansbury (twsansbury at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost/python.hpp>
#include <sample/task_list.hpp>
#include <sample/task_list_observer.hpp>

namespace py_sample {

void init_task_list()
{
  namespace python = boost::python;

  python::class_<sample::task_list::tasks
      >("TaskListTasks", // Python class name.
        python::no_init) // Suppress construction from within Python.
    .def("__iter__", python::iterator<sample::task_list::tasks>())
    ;

  // Expose task_list.
  python::class_<sample::task_list,
        boost::noncopyable // task_list is non-copyable.
      >("TaskList", // Python class name.
        python::no_init) // Suppress Boost.Python constructors.
    // Provide constructor that delegates to factory.
    .def("__init__", python::make_constructor(&sample::task_list::create))
    .def("add", &sample::task_list::add)
    .def("remove", &sample::task_list::remove)
    .def("all", &sample::task_list::all)
    .def("attach", &sample::task_list::attach)
    .def("detach", &sample::task_list::detach)
    ;

  // Free functions.
  python::def("active", &sample::active);
  python::def("completed", &sample::completed);
}

} // namespace py_sample

