#include <string>

#include <iostream>

#include <bitset>

std::string offset(const std::string &s) {
    std::string total = "";
    for (auto i: s) {
        total += std::to_string(int(i << 4)) + " ";
    };
    return total;
}

std::string string_to_hex(const std::string &input) {
    static
    const char hex_digits[] = "0123456789ABCDEF";

    std::string output;
    output.reserve(input.length() * 2);
    for (unsigned char c: input) {
        output.push_back(hex_digits[c >> 4]);
        output.push_back(hex_digits[c & 15]);
    }
    return output;
}

std::bitset<32> to_bitset(std::string s) {
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
    std::string ans = to_string(to_bitset(str1) ^ to_bitset(str2));
    return ans;
}

std::string crypto(std::string password, std::string login) {
    std::string new_pass = string_to_hex(offset(password));
    std::string ans = xoring(new_pass, login);
    return ans;
};

std::string invert_login(std::string admin) {
    reverse(admin.begin(), admin.end());
    return admin;
}

int main() {
    for (;;) {
        std::string login;
        std::cout << "Enter login: ";
        std::cin >> login;
        std::string input;
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