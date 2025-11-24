#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define OTP_LENGTH 6
#define MAX_ATTEMPTS 3

// Function to generate a random OTP
void generateOTP(char *otp) {
    for (int i = 0; i < OTP_LENGTH; i++) {
        otp[i] = '0' + rand() % 10;  // random digit 0–9
    }
    otp[OTP_LENGTH] = '\0'; // null-terminate string
}

int main() {
    srand(time(0));  // seed random number generator

    char otp[OTP_LENGTH + 1];
    generateOTP(otp);

    printf("Your OTP is: %s\n", otp);  // In real system, send via SMS/Email

    char userInput[OTP_LENGTH + 1];
    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        printf("Enter OTP: ");
        scanf("%s", userInput);

        if (strcmp(userInput, otp) == 0) {
            printf("✅ OTP Verified Successfully!\n");
            return 0;
        } else {
            printf("❌ Invalid OTP. Try again.\n");
            attempts++;
        }
    }

    printf("Too many failed attempts. Access denied.\n");
    return 1;
}