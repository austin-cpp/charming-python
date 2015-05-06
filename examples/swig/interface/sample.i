/*
 * sample.i
 * ~~~~~~~~
 *
 * Copyright (c) 2015 Tanner Sansbury (twsansbury at gmail dot com)
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

/* Enable directors, as at least one class has virtual methods. */
%module(directors="1") sample

%include "task.i"
%include "task_list.i"
%include "task_list_observer.i"
