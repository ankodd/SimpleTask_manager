Russian language Documentation Task - Manager(beta version) 


Основные функции:
1. Добавлять задачу,название, описание. —> completed
2. Удалить задачу из списка задач —> completed
3. Возможность редактировать задачу -> in developing…
4. Сохранять задачи в файл. —> completed
5. Выводить задачу из файла. —> in developing…
6. Удалять задачи из файла. -> completed
7. Просмотреть все задачи. —> completed
Какие могут возникнуть ошибки:
1. Ошибка создания задачи, с имя которой уже занято другой задачей.
Все команды:
1. Добавить задачу:
task-manager create название_задачи описание
2. Удалить задачу:
task-manager delete название_задачи
3. Сохранить задачу:
        task-manager save название_задачи
4. Удалить задачу из файла:
task-manager delete_saved_task название_задачи
5. Просмотреть все текущие задачи:
        task-manager display_tasks