#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TODO_LIST_LENGTH 100
#define MAX_TASK_TITLE_LENGTH 100

typedef struct {
    int taskNo;
    char taskTitle[MAX_TASK_TITLE_LENGTH];
    bool isCompleted;
} Todo;

int removeNewline(char *str) {
    char *newline = strchr(str, '\n');
    if (newline != NULL) {
        *newline = '\0';
    }
    return 0;
}

int addTask(Todo todoList[]) {
    puts("=== addTask ===");

    for (int i = 0; i < MAX_TODO_LIST_LENGTH; i ++) {
        if (todoList[i].taskNo == 0) {
            puts("taskTitle: ");
            fgets(todoList[i].taskTitle, MAX_TASK_TITLE_LENGTH, stdin);
            removeNewline(todoList[i].taskTitle);

            todoList[i].taskNo = i + 1;
            todoList[i].isCompleted = false;

            return 0;
        }
    }
}

int showTasks(Todo todoList[]) {
    puts("=== showTasks ===");
    
    for (int i = 0; i < MAX_TODO_LIST_LENGTH; i ++) {
        if (todoList[i].taskNo != 0) {
            printf("TaskNo %d: %s [%s]\n", todoList[i].taskNo, todoList[i].taskTitle, todoList[i].isCompleted ? "+" : " ");
        }
    }
}

int main() {
    Todo todoList[MAX_TODO_LIST_LENGTH] = {0};
    int userChoice;

    while (1) {
        puts("=== Todo List Menu ===");

        puts("1. Add Task");
        puts("2. Show Tasks");
        puts("3. Delete Task");
        puts("4. Complete Task");
        puts("5. Exit");

        puts("Choose an option: ");
        scanf("%d", &userChoice);
        getchar();

        switch (userChoice) {
            case 1:
                addTask(todoList);
                break;
            case 2:
                showTasks(todoList);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                exit(0);
                break;
            default:
        }
    }
}