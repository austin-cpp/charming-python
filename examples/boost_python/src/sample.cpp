#include <boost/python.hpp>

namespace py_sample {
extern void init_task();
extern void init_task_list();
extern void init_task_list_observer();
} // namespace py_sample

BOOST_PYTHON_MODULE(sample)
{
  py_sample::init_task();
  py_sample::init_task_list();
  py_sample::init_task_list_observer();
}