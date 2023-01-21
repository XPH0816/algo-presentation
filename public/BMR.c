#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define STRING_LENGTH 100
#define MIN_AGE 1
#define MAX_AGE 100
#define MIN_WEIGHT 1
#define MAX_WEIGHT 300
#define MIN_HEIGHT 1
#define MAX_HEIGHT 300

typedef struct UserData
{
    char name[STRING_LENGTH];
    int age;
    float weight;
    float height;
    char gender;
    char activityLevel[STRING_LENGTH];
    float activityLevelValue;
} User;

int userSize;

void clearStdin()
{
    while (getchar() != '\n')
        ; // clear stdin
}

void clearScreen()
{
    printf("\033[2J\033[1;1H");
}

void print_prompt()
{
    printf("\n>> ");
}

char getValidChar(const char *validChars, const char *prompt)
{
    char c;
    while (1)
    {
        printf("\n%s", prompt);
        print_prompt();
        c = toupper(fgetc(stdin));
        clearStdin();
        if (strchr(validChars, c) != NULL)
        {
            break;
        }
        printf("Invalid input! Please enter (");
        for (int i = 0; i < strlen(validChars); i++)
        {
            if (i > 0)
            {
                printf("/");
            }
            printf("%c", toupper(validChars[i]));
        }
        printf(") only. \n");
    }
    return c;
}

int getValidInt(const char *term, int min, int max)
{
    int i;
    char input[STRING_LENGTH];
    while (1)
    {
        printf("\nEnter your %s", term);
        print_prompt();
        fgets(input, STRING_LENGTH, stdin);
        i = atoi(input);
        // scanf("%d", &i);
        // clearStdin();
        if (i >= min && i <= max)
        {
            return i;
        }
        printf("Please enter a valid %s between %d and %d.\n", term, min, max);
    }
}

float getValidFloat(const char *term, float min, float max)
{
    float f;
    char input[STRING_LENGTH];
    while (1)
    {
        printf("\nEnter your %s", term);
        print_prompt();
        fgets(input, STRING_LENGTH, stdin);
        f = atof(input);
        // scanf("%f", &f);
        // clearStdin();
        if (f >= min && f <= max)
        {
            return f;
        }
        printf("Please enter a valid %s between %.2f and %.2f.\n", term, min, max);
    }
}

char *getValidString(const char *term)
{
    char *s = malloc(STRING_LENGTH);
    while (1)
    {
        printf("\nEnter your %s", term);
        print_prompt();
        fgets(s, STRING_LENGTH, stdin);
        // remove the newline character from the string
        s[strcspn(s, "\n")] = 0;
        const char * numbers = "0123456789";
        if (strpbrk(s, numbers) != NULL)
        {
            printf("Invalid input! Please enter a valid %s.\n", term);
            continue;
        }
        if (strlen(s) != 0 && strlen(s) <= STRING_LENGTH)
        {
            return s;
        }
        printf("Invalid input!\n");
    }
}

void deskJobA(User *user)
{
    switch (getValidChar("YN", "Are you working on desk job? (Y/N) :"))
    {
    case 'Y':
        strcpy(user->activityLevel, "Very Active");
        user->activityLevelValue = 1.725;
        break;

    case 'N':
        strcpy(user->activityLevel, "Extra Active");
        user->activityLevelValue = 1.9;
        break;
    }
}

void deskJobB(User *user)
{
    switch (getValidChar("YN", "Are you working on desk job? (Y/N) :"))
    {
    case 'Y':
        strcpy(user->activityLevel, "Sedentary");
        user->activityLevelValue = 1.2;
        break;

    case 'N':
        strcpy(user->activityLevel, "Light Activity");
        user->activityLevelValue = 1.375;
        break;
    }
}

void exercise(User *user)
{
    printf("\nHow often do you exercise? Please enter a number.\n");
    printf("1: Daily Exercise");
    printf("\n2: 6-7 days per week exercise");
    printf("\n3: 3-5 days per week exercise");
    printf("\n4: 1-3 days per week exercise");
    printf("\n5: None of the above.\n");
    switch (getValidInt("option", 1, 5))
    {
    case 1:
        deskJobA(user);
        break;

    case 2:
        strcpy(user->activityLevel, "Very Active");
        user->activityLevelValue = 1.725;
        break;

    case 3:
        strcpy(user->activityLevel, "Moderate Activity");
        user->activityLevelValue = 1.55;
        break;

    case 4:
        strcpy(user->activityLevel, "Light Activity");
        user->activityLevelValue = 1.375;
        break;

    case 5:
        deskJobB(user);
        break;
    }
}

void ExtraActive(User *user)
{
    switch (getValidChar("YN", "Do you have training more than 2 days? (Y/N) :"))
    {
    case 'Y':
        strcpy(user->activityLevel, "Extra Active");
        user->activityLevelValue = 1.9;
        break;

    case 'N':
        exercise(user);
        break;
    }
}

void surveyModule(User *user)
{
    clearScreen();
    printf("Welcome to our Survey Module !\nPlease answer the following questions to get your Level of Activity.\n");
    switch (getValidChar("YN", "Are you an athlete / sportsman / gym's person? (Y/N) :"))
    {
    case 'Y':
        ExtraActive(user);
        break;

    case 'N':
        exercise(user);
        break;
    }
}

void getInfo(User *user)
{
    clearScreen();
    strcpy(user->name, getValidString("name"));
    user->age = getValidInt("age", MIN_AGE, MAX_AGE);
    user->weight = getValidFloat("weight (kg)", MIN_WEIGHT, MAX_WEIGHT);
    user->height = getValidFloat("height (cm)", MIN_HEIGHT, MAX_HEIGHT);
    user->gender = getValidChar("MF", "Enter your gender (M/F): ");
    surveyModule(user);
}

float calculateBMR(User *user)
{
    switch(user->gender)
    {
        case 'M':
            return 66 + (13.7 * user->weight) + (5 * user->height) - (6.8 * user->age);
            break;
        case 'F':
            return 655 + (9.6 * user->weight) + (1.8 * user->height) - (4.7 * user->age);
            break;
    }
}

float calculateDCR(User *user)
{
    return calculateBMR(user) * user->activityLevelValue;
}

void printInfo(User user)
{
    clearScreen();
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %.2f\n", user.weight);
    printf("Height: %.2f\n", user.height);
    printf("Gender: %c\n", user.gender);
    printf("Level of Activity: %s\n", user.activityLevel);
    printf("BMR: %.2f\n", calculateBMR(&user));
    printf("DCR: %.2f\n", calculateDCR(&user));
    printf("Note: Based on the information you provided, you would need %.2f calories from food to sustain yoru daily activities.\n", calculateDCR(&user));
}

int MainMenu()
{
    printf("Welcome to our DCR & BMR Calculator System !\n");
    printf("1. Calculate DCR & BMR\n");
    printf("2. See the list of Previous Calculations\n");
    printf("3. Exit\n");
    return getValidInt("option", 1, 3);
}

void saveToFile(User *user)
{
    FILE *fptr;
    fptr = fopen("DCR.db", "a");
    // Write the raw data to the file
    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    fseek(fptr, 0, SEEK_END);
    fwrite(user, sizeof(User), 1, fptr);
    fclose(fptr);
}

User * readFromFile()
{
    FILE *fptr;
    fptr = fopen("DCR.db", "r");
    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    fseek(fptr, 0, SEEK_END);
    int size = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);
    User *user = (User *)malloc(size);
    userSize = size/sizeof(User);
    fread(user, sizeof(User), userSize, fptr);
    fclose(fptr);
    return user;
}

void printList(User *user)
{
    clearScreen();
    printf("List of Previous Calculations\n");
    printf("Bil\tName\t\t\tAge\tWeight\tHeight\tGender\tLevel of Activity\t\tBMR\t\tDCR\n");
    for(int i = 0; i < userSize; i++)
    {
        printf("%02d.\t%-20s\t%2d\t%.2f\t%.2f\t%c\t%-17s\t\t%.2f\t\t%.2f\n", i+1,user[i].name, user[i].age, user[i].weight, user[i].height, user[i].gender, user[i].activityLevel, calculateBMR(&user[i]), calculateDCR(&user[i]));
    }
}

int main()
{
    do
    {
        User user;
        clearScreen();
        
        switch (MainMenu())
        {
        case 1:
            getInfo(&user);
            printInfo(user);
            saveToFile(&user);
            break;
        case 2:
            printList(readFromFile());
            break;
        case 3:
            printf("Thank you for using our DCR Calculator System !\n");
            exit(EXIT_SUCCESS);
            break;
        }

    } while (getValidChar("YN", "Do you want to continue? (Y/N): ") == 'Y');

    return 0;
}