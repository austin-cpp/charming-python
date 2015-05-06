import sample

task_list = sample.TaskList()

task1 = sample.Task('a', False)

task_list.add(task1)
task_list.add(sample.Task('b', False))

class VerboseObserver(sample.TaskListObserver):
    def on_add(self):
        print "on add"

    def on_remove(self):
        print "on remove"

observer = VerboseObserver()
task_list.attach(observer)

task_list.add(sample.Task('c', True))

print "all task: "
for task in task_list.all():
    print "  " + task.title, task.completed

task1.completed = True

print "active task:"
for task in sample.active(task_list):
    print "  " + task.title

print "removing completed: "
for task in sample.completed(task_list):
    print "  " + task.title
    task_list.remove(task)

task_list.detach(observer)
for task in task_list.all():
    task_list.remove(task)