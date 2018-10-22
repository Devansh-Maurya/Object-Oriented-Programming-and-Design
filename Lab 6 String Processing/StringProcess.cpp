#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class StringProcess {
public:

    const static char SPACE = ' ';

    static void countChar(string str, int characters[26]) {
        unsigned long stringLen = str.length();

        //Check every character till the end of the string
        for (int i = 0; i < stringLen; ++i) {
            char& ch = str.at(i);

            //If letter is in uppercase
            if ((ch >=65) && (ch <= 90)) {
                characters[ch - 65]++;
            }
            //If letter is in lowercase
            else if ((ch >= 97) || (ch <= 122)) {
                characters[ch - 97]++;
            }
        }
    }

    static void countWordLengths(string str, int* wordLengths, int maxLength) {

        int charCount = 0;
        unsigned long stringLen = str.length();

        //Check every character till the end of the string
        for (int i = 0; i < stringLen; ++i) {
            if (str.at(i) != SPACE) {
                //If character is not a space, increase count
                charCount++;
            } else {
                //If character is a space
                if (charCount <= maxLength)
                    //if character length is in range, increase word count at that position
                    wordLengths[charCount]++;
                //Re-initialize word count to 0
                charCount = 0;
            }
        }
        //Count last word
        if (charCount <= maxLength)
            wordLengths[charCount]++;
    }

    static string dateFormat(string date) {
        int len = date.length();
        string formattedDate;
        char ch[3];
        ch[2] = '\0';
        int dateNumSegment;

        switch (len) {
            case 10:
                //Complete date in proper format
                //Format month as name
                ch[0] = date.at(0);
                ch[1] = date.at(1);
                dateNumSegment = atoi(ch);
                formattedDate.append(getMonthInWord(dateNumSegment));
                formattedDate.append(" ");

                //Add day to the formatted date
                ch[0] = date.at(3);
                ch[1] = date.at(4);
                formattedDate.append(ch);
                formattedDate.append(", ");

                //Add year to the formatted date
                ch[0] = date.at(6);
                ch[1] = date.at(7);
                formattedDate.append(ch);
                ch[0] = date.at(8);
                ch[1] = date.at(9);
                formattedDate.append(ch);
                break;

            case 9:
                //Day has been given in single digit
                if (date.at(2) == '/') {
                    //Format month as name
                    ch[0] = date.at(0);
                    ch[1] = date.at(1);
                    dateNumSegment = atoi(ch);
                    formattedDate.append(getMonthInWord(dateNumSegment));
                    formattedDate.append(" ");

                    //Add date to the formatted date
                    ch[0] = date.at(3);
                    formattedDate.append(ch);
                    formattedDate.append(", ");

                    //Add year to the formatted date
                    ch[0] = date.at(5);
                    ch[1] = date.at(6);
                    formattedDate.append(ch);
                    ch[0] = date.at(7);
                    ch[1] = date.at(8);
                    formattedDate.append(ch);
                    break;
                } else {
                    //Month has been given in single digit
                    //Format month as name
                    ch[0] = date.at(0);
                    dateNumSegment = atoi(ch);
                    formattedDate.append(getMonthInWord(dateNumSegment));
                    formattedDate.append(" ");

                    //Add date to the formatted date
                    ch[0] = date.at(2);
                    ch[1] = date.at(3);
                    formattedDate.append(ch);
                    formattedDate.append(", ");

                    //Add year to the formatted date
                    ch[0] = date.at(5);
                    ch[1] = date.at(6);
                    formattedDate.append(ch);
                    ch[0] = date.at(7);
                    ch[1] = date.at(8);
                    formattedDate.append(ch);
                }
                break;
            case 8:
                //Month and day both have been given in single digit
                //Format month as name
                ch[0] = date.at(0);
                dateNumSegment = atoi(ch);
                formattedDate.append(getMonthInWord(dateNumSegment));
                formattedDate.append(" ");

                //Add date to the formatted date
                ch[0] = date.at(2);
                formattedDate.append(ch);
                formattedDate.append(", ");

                //Add year to the formatted date
                ch[0] = date.at(4);
                ch[1] = date.at(5);
                formattedDate.append(ch);
                ch[0] = date.at(6);
                ch[1] = date.at(7);
                formattedDate.append(ch);
        }
        return formattedDate;
    }

    static string getMonthInWord(int month) {
        switch (month) {
            case 1:
                return "January";
            case 2:
                return "February";
            case 3:
                return "March";
            case 4:
                return "April";
            case 5:
                return "May";
            case 6:
                return "June";
            case 7:
                return "July";
            case 8:
                return "August";
            case 9:
                return "September";
            case 10:
                return "October";
            case 11:
                return "November";
            case 12:
                return "December";
        }
    }
};