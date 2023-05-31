#include "includeStatements.h"
#include "functions.h"

/*
    Work In Progress
*/
int saveToFileArrayFormat(Array* array, char* filepath)
{
    if (array == NULL || filepath == NULL)
    {
        return -1;
    }
    FILE* file = fopen(filepath, "w");
    if (file == NULL)
    {
        return -1;
    }
    fwrite(array->name, sizeof(char), strlen(array->name), file);
    fwrite("\n", sizeof(char), 1, file);
    fwrite(array->type, sizeof(char), strlen(array->type), file);
    fwrite("\n", sizeof(char), 1, file);
    fwrite(&(array->dimensionCount), sizeof(int), 1, file);
    fwrite("\n", sizeof(char), 1, file);
    for (int i = 0; i < array->dimensionCount; i++)
    {
        fwrite(&(array->dimensionValue[i]), sizeof(int), 1, file);
        fwrite(" ", sizeof(char), 1, file);
    }
    fwrite(&(array->size), sizeof(ssize_t), 1, file);
    fwrite(array->arr, array->size, 1, file);
    fclose(file);
    return 0;
}

/*
    Work In Progress
*/
Array* loadFromFile(char* filepath)
{
    FILE* file = fopen(filepath, "r");
    if (file == NULL)
    {
        return NULL;
    }
    Array* re = calloc(1, sizeof(Array));

    if (fgets(re->name, MAX_CHARACTER_BUFFER_LENGTH, file) != NULL) 
    {
        size_t length = strlen(re->name);
        if (length > 0 && re->name[length - 1] == '\n') 
        {
            re->name[length - 1] = '\0';
        }
    }

    if (fgets(re->type, MAX_CHARACTER_BUFFER_LENGTH, file) != NULL) 
    {
        size_t length = strlen(re->type);
        if (length > 0 && re->type[length - 1] == '\n') 
        {
            re->type[length - 1] = '\0';
        }
    }

    return re;
}