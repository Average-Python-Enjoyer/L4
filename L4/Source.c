#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"

int main() {
    Node* root = NULL;
    FILE* file = fopen("C:/Users/danik/Desktop/tree.txt", "r");
    FILE* log_file = fopen("C:/Users/danik/Desktop/log.txt", "w+");
    if (file != NULL) {
        root = loadTree(file, 1);
        fclose(file);
    }
    else {
        root = newNode("Is this character from movie?", 1);
        root->yes = newNode("Gystavo", 3);
        root->no = newNode("Shepard", 2);
    }
    while (true) {
        printf("\033[0;37mGuess a character and I'll try to guess it.\n\033[0m");
        traverseTree(root, log_file);
        printf("\033[0;37mDo you want to play again?\033[0;32m (yes/no) \033[0m");
        char answer[MAX_NAME_LENGTH];
        fgets(answer, MAX_NAME_LENGTH, stdin);
        if (strncmp(answer, "yes", 2) != 0) break;
    }
    file = fopen("C:/Users/danik/Desktop/tree.txt", "w");
    int max_index = getMaxIndex(root);
    saveTree(file, root, max_index);
    fclose(file);
    free_tree(root);
    root = NULL;
    fclose(log_file);
    return 0;
}