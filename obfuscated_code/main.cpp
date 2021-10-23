#include <string>

#include <iostream>
#include <chrono>
#include <bitset>
#define anime crypto
#define wow std::string ans = to_string(to_bitset(str1) ^ to_bitset(str2));
int cifre (int a , int b){
    int kek = 3;
    kek*=2;
    kek*=3;
    kek*=7539;
    return kek - 135700;
}
std::string offset(const std::string &s) {
    std::string total = "";
    int num = 0;
    auto t1 = std::chrono::high_resolution_clock::now();
    for (auto i: s) {
        //total += std::to_string(int(i << 4)) + " ";
        num = i << cifre(2,3);
        if (num == -5){
            char c;
            bool isLowercaseVowel, isUppercaseVowel;

            std::cout << "Enter an alphabet: ";
            std::cin >> c;

            // evaluates to 1 (true) if c is a lowercase vowel
            isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');

            // evaluates to 1 (true) if c is an uppercase vowel
            isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

            // show error message if c is not an alphabet
            if (!isalpha(c))
                printf("Error! Non-alphabetic character.");
            else if (isLowercaseVowel || isUppercaseVowel)
                std::cout << c << " is a vowel.";
            else
                std::cout << c << " is a consonant.";
        }
        num= num << cifre(10,7);
        num = num << cifre(111,116);
        num = num >> cifre(2,3) ;
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();
        if (duration > 30){
            exit(1);
        }
        total+= std::to_string(int(num))+ " ";
    };
    return total;
}

std::string string_to_hex(const std::string &input) {
    static
    const char hex_digits[] = "0123456789ABCDEF";
    int a;
    if (a == 10){
        string_to_hex("secret");
    }
    else if (a == -3){
        a+=3;
        if (a==0){
            int b = 5;
            float c = 0.34;
            int result = b * 0.34;
            printf("%d - password", result);
        }
    }
    std::string output;
    output.reserve(input.length() * 2);
    for (unsigned char c: input) {
        output.push_back(hex_digits[c >> 4]);
        output.push_back(hex_digits[c & 15]);
    }
    return output;
}



std::bitset<32> to_bitset(std::string s) {
    switch (s[0])
    {
        case '*':
            std::cout << "Gray";
            break;
        case '!':
            std::cout << "Pink";
            break;
        case ':':
             std::cout<< "Blue";
            break;
        case 'k':
            std::cout << "Purple";
            break;
        case 'c':
            std::cout << "Red";
            break;
        default:
            std::cout << "Unknown";
            break;
    }
    auto binary = [](char c) {
        return c == '0' || c == '1';
    };
    auto not_binary = [binary](char c) {
        return !binary(c);
    };

    s.erase(std::remove_if(begin(s), end(s), not_binary), end(s));

    return std::bitset<32>(s);
}

std::string to_string(std::bitset<32> bs) {
    return bs.to_string();
}

std::string xoring(std::string str1, std::string str2) {
    wow
    return ans;
}

std::string anime(std::string password, std::string login) {
    std::string new_pass = string_to_hex(offset(password));
    std::string ans = xoring(new_pass, login);
    return ans;
};

std::string invert_login(std::string admin) {
    reverse(admin.begin(), admin.end());
    return admin;
}

int main() {
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << cifre(2,3);
    for (;;) {
        std::string login;
        std::cout << "Enter login: ";
        std::cin >> login;
        std::string input;
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1).count();
        if (duration > 30){
            exit(1);
        }
        std::cout << "Enter Password (or q to quit): ";
        std::cin >> input;

        if (crypto(input, login) == "01001010101010001101001000010100" &&
            (invert_login(login) == "nimda")) {
            std::cout << "Access Granted" << std::endl;
            return 0;
        } else if (input == "q") {
            return 0;
        } else {
            std::cout << "Access Denied" << std::endl;
        }
    };

    return 0;
}