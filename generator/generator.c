#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

#include"external_dependencies/cJSON.h"
#include"test_profiles.h"

UINT* (*funcs[4])(unsigned int) = {&default_generator, &pae_generator, &tsp_generator, &all_generator};

struct SequenceParameters{
    const char* test_profile;
    unsigned long total_pulses;
};

UINT* generate_sequence(struct SequenceParameters* parameters);

char* read_file(const char* filename)
{
    FILE *f = fopen(filename, "rb");
    if (f == NULL){
        printf("Can't open %s file. Make sure it is represented in current working folder", filename);
        return NULL;
    }
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET); 

    char *string = malloc(fsize + 1);
    if (string == NULL)
    {
        return NULL;
    }
    fread(string, fsize, 1, f);
    fclose(f);

    string[fsize] = 0;
    return string;
}

void write_sequence_to_file(const char* filename, UINT* sequence, unsigned int sequence_len)
{
    int written = 0;
    FILE *f;
    char path[127];
    strcpy(path, filename);
    strcat(path, ".txt");
    f = fopen(path, "wb");
    if (f == NULL)
    {
        printf("Can't open file to write");
        return;
    }
    for (size_t i = 0u; i < sequence_len; i++)
    {
        fprintf(f, "%d\n", sequence[i]);
    }
    fclose(f); 
}

int generate_testcases()
{    
    char* buffer;
    buffer = read_file("testcases.json");
    if (buffer == NULL)
    {
        return EXIT_FAILURE;
    }
    cJSON* json = cJSON_Parse(buffer);
    cJSON* testcase = NULL;
    cJSON_ArrayForEach(testcase, json)
    {
        cJSON* name = cJSON_GetObjectItem(testcase, "name");
        cJSON* total_pulses = cJSON_GetObjectItem(testcase, "total_pulses");
        cJSON* profile = cJSON_GetObjectItem(testcase, "profile");

        struct SequenceParameters* params;
        params = malloc(sizeof(*params));
        params->test_profile = profile->valuestring;
        params->total_pulses = total_pulses->valueint;

        write_sequence_to_file(name->valuestring, 
            generate_sequence(params), 
            total_pulses->valueint);

        free(params);
    }
    cJSON_Delete(json);
    free(buffer);
    return EXIT_SUCCESS;
};

UINT* generate_sequence(struct SequenceParameters* parameters)
{
    UINT* (*generate)(unsigned int) = funcs[parse_profile(parameters->test_profile)];
    return generate(parameters->total_pulses);
}

int main()
{
    srand(time(NULL));

    generate_testcases();

    return EXIT_SUCCESS;
}