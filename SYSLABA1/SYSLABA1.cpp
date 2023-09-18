#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>

bool isconsonant(char c) {
    // Перевіряємо, чи є символ приголосною літерою
    return (c == 'b' || c == 'c' || c == 'd' || c == 'f' || c == 'g' || c == 'h' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z');
}

bool hasDoubleConsonants(const std::string& word) {
    for (int i = 0; i < word.length() - 1; i++) {
        if (word[i] == word[i + 1] && isalpha(word[i]) && isalpha(word[i + 1]) && isconsonant(word[i])) {
            return true;
        }
    }
    return false;
}



int main() {
    std::ifstream file("input.txt"); 
    if (!file.is_open()) {
        std::cerr << "Неможливо відкрити файл!" << std::endl;
        return 1;
    }

    std::set<std::string> uniqueWords; // Використовуємо множину для збереження унікальних слів

    std::string word;
    while (file >> word) {
        // Видаляємо непотрібні символи зі слова
        word.erase(std::remove_if(word.begin(), word.end(), [](char c) { return !isalpha(c); }), word.end());

        // Перевіряємо, чи слово має здвоєні приголосні літери і чи не перевищує довжину 30 символів
        if (word.length() <= 30 && hasDoubleConsonants(word)) {
            uniqueWords.insert(word);
        }
    }

    // Виводимо унікальні слова
    for (const std::string& uniqueWord : uniqueWords) {
        std::cout << uniqueWord << std::endl;
    }


    file.close();
    return 0;
}
