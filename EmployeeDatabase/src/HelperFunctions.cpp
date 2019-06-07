
#include "HelperFunctions.hpp"

int pypert::GetValidSignedIntegerInput() {
    bool valid = false;
    int option = 0;
    while (!valid) {
        cin >> option;
        if (cin.fail()) {
            cout << ": " << flush;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            continue;
        }
        valid = true;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    return option;
}

float pypert::GetValidFloatInput() {
    bool valid = false;
    float option = 0.0f;
    while (!valid) {
        cin >> option;
        if (cin.fail()) {
            cout << ": " << flush;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            continue;
        }
        valid = true;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    return option;
}


char pypert::GetValidCharInput() {
    bool valid = false;
    string input;
    while(!valid) {
        getline(cin, input);
        if(input.length() > 1) {
             std::cout << ": " << std::flush;
             continue;
        }
        valid = true;
    }
    return input[0];
}

string pypert::StringToTitle(string s) {
    if (s.empty()) {
        return "";
    }
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    s[0] = std::toupper(s[0]);

    return s;
    // int previousSpaceIndex = 0;
    // bool done = false;
    // string newString = "";
    // while(!done) {
    //     int currentSpaceIndex = s.find (" ");
    //     string sSubstring = s.substr(previousSpaceIndex, (currentSpaceIndex - previousSpaceIndex));
    //     std::transform(sSubstring.begin(), sSubstring.end(), sSubstring.begin(), ::tolower);
    //     sSubstring[0] = std::toupper(sSubstring[0]);
    //     newString.append(sSubstring.append(" "));
    //     previousSpaceIndex = currentSpaceIndex;
    //     currentSpaceIndex = s.substr(currentSpaceIndex + 1, (s.size() - currentSpaceIndex)).find(" ");
        
    // }

    // return newString;
}