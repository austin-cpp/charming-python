/*
 * task_list_observer.i
 * ~~~~~~~~~~~~~~~~~~~~
 *
 * Copyright (c) 2015 Tanner Sansbury (twsansbury at gmail dot com)
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

/* Enable director for virtual method handling. */
%feature("director") sample::task_list_observer;

/* Rename to Python naming conventions. */
%rename(TaskListObserver) sample::task_list_observer;

%include <sample/task_list_observer.hpp>

/** Code injected into wrapping as-is. */
%{
  #include <sample/task_list_observer.hpp>
%}
