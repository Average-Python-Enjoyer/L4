#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"

int main() {
    Node* root = NULL;
    FILE* file = fopen("C:/Users/danik/Desktop/tree.txt", "r");
    FILE* log_file = fopen("C:/Users/danik/Desktop/log.txt", "w+");
    log_action(log_file, "Program started");
    if (file != NULL) {
        root = loadTree(file, 1);
        fclose(file);
        log_action(log_file, "Tree loaded from file");
    }
    else {
        root = newNode("Is this character from movie?", 1);
        root->yes = newNode("Gystavo", 3);
        root->no = newNode("Shepard", 2);
        log_action(log_file, "New tree created");
    }
    while (true) {
        printf("\033[0;37mGuess a character and I'll try to guess it.\n\033[0m");
        log_action(log_file, "New game started");
        traverseTree(root, log_file);
        printf("\033[0;37mDo you want to play again?\033[0;32m (yes/no) \033[0m");
        char answer[MAX_NAME_LENGTH];
        fgets(answer, MAX_NAME_LENGTH, stdin);
        if (strncmp(answer, "yes", 2) != 0) break;
        log_action(log_file, "User chose to play again");
    }
    file = fopen("C:/Users/danik/Desktop/tree.txt", "w");
    int max_index = getMaxIndex(root);
    saveTree(file, root, max_index);
    fclose(file);
    free_tree(root);
    root = NULL;
    log_action(log_file, "Program exited");
    fclose(log_file);
    return 0;
}