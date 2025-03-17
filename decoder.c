#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>


int* read_numbers_from_file(const char* filename, int* count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        *count = 0;
        return NULL;
    }

    int capacity = 10;
    int* numbers = malloc(capacity * sizeof(int));
    *count = 0;
    char line[32];

    while (fgets(line, sizeof(line), file)) {
        if (*count >= capacity) {
            capacity *= 2;
            numbers = realloc(numbers, capacity * sizeof(int));
        }
        
        numbers[*count] = atoi(line);
        (*count)++;
    }

    fclose(file);
    return numbers;
}

void write_sequence_to_file(const char* filename, int* sequence, unsigned int sequence_len)
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


int decode_pulse(int pulse_duration) {

    if (pulse_duration < 7) { // 1 мкс * 7 МГц = 7 тактов
        return -1;
    } else if (pulse_duration >= 7 && pulse_duration < 14) { // 1 мкс * 7 МГц = 7 тактов, 2 мкс * 7 МГц = 14 тактов
        return 0;
    } else if (pulse_duration >= 14 && pulse_duration < 27) { // 2 мкс * 7 МГц = 14 тактов, 3 мкс * 7 МГц = 21 тактов
        return 1;
    } else if (pulse_duration >= 27) { // 3 мкс * 7 МГц = 21 тактов
        return -2;
    }
    return __INT_MAX__;
}

int* decode_sequence(int* sequence, unsigned int sequence_len) {
    int* decoded_sequence = malloc(sequence_len * sizeof(int));
    for (size_t i = 0u; i < sequence_len; i++) {
        decoded_sequence[i] = decode_pulse(sequence[i]);
    }
    return decoded_sequence;
}

int main(int argc, char *argv[]) {
    unsigned int sequence_len = 0;
    int* sequence = read_numbers_from_file(argv[1], &sequence_len);

    write_sequence_to_file("binary_sequence_out", decode_sequence(sequence, sequence_len), sequence_len);

    free(sequence);
    return 0;
}