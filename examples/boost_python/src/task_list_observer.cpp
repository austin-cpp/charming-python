//
// task_list_observer.cpp
// ~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2015 Tanner Sansbury (twsansbury at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost/python.hpp>
#include <sample/task_list_observer.hpp>

namespace py_sample {

// Create a wrapper class that overrides the pure-virtual functions, making it
// concreate class.  These overrides will then delegate to the Python object.
namespace {

struct task_list_observer_wrapper
  : sample::task_list_observer,
    boost::python::wrapper<sample::task_list_observer>
{
  void on_add()
  {
    this->get_override("on_add")();
  }

  void on_remove()
  {
    this->get_override("on_remove")();
  }
};

} // namespace

void init_task_list_observer()
{
  namespace python = boost::python;

  // Expose task_list_observer.
  python::class_<task_list_observer_wrapper,
        boost::noncopyable // Required for pure-virtuals.
      >("TaskListObserver") // Python class name.
    .def("on_add", 
         python::pure_virtual(&sample::task_list_observer::on_add))
    .def("on_remove",
         python::pure_virtual(&sample::task_list_observer::on_remove))
    ;
}

} // namespace py_sample
