# CAPTCHA System – General Architecture

## Introduction
CAPTCHA stands for **Completely Automated Public Turing test to tell Computers and Humans Apart**.  
It is a security mechanism used to distinguish human users from automated programs (bots). CAPTCHA systems are commonly used on websites to prevent spam, automated registrations, and malicious activities.

## General Architecture of a CAPTCHA System

A CAPTCHA system typically works through a sequence of stages that ensure only humans can successfully pass the verification process.

### 1. CAPTCHA Generation
The first stage is the generation of a CAPTCHA challenge. In this stage, the system creates a random sequence of characters. These characters usually include a mixture of uppercase letters, lowercase letters, and digits. The purpose of generating random characters is to make the CAPTCHA unpredictable and difficult for automated programs to guess.

### 2. CAPTCHA Presentation
After generating the CAPTCHA, the system displays it to the user. The user is asked to observe the characters and type them exactly as shown. In simple programs, the CAPTCHA is displayed as plain text. In real-world systems, the characters may be distorted or embedded in images to make automated recognition more difficult.

### 3. User Input Collection
Once the CAPTCHA is displayed, the system waits for the user to enter the characters they see. The user input is collected and stored temporarily for comparison with the generated CAPTCHA.

### 4. Verification
In this stage, the system compares the CAPTCHA generated earlier with the input provided by the user. This comparison is usually done using a string comparison method. If both strings match exactly, the verification is considered successful.

### 5. Access Decision
The final stage determines whether the user is allowed to proceed. If the user enters the correct CAPTCHA, access is granted, indicating that the user is likely a human. If the input is incorrect, the system allows the user to try again for a limited number of attempts. If the maximum number of attempts is exceeded, access is denied.

## Conclusion
The CAPTCHA system provides a simple yet effective method for protecting systems from automated bots. By generating random challenges and verifying user responses, it ensures that only genuine human users can access certain services or perform specific actions.
