#ifndef DIALOGUTILS_H
#define DIALOGUTILS_H

#include <map>
#include <string>
#include "model/AbstractDialog.hpp"

class DialogUtils {
    public:
        static const std::string QUESTION_SPAWN;
        static const std::string QUESTION_LEVEL_UP;

        static const std::string ANSWER_YES;
        static const std::string ANSWER_NO;
        static const std::string ANSWER_PASS;
        static const std::string ANSWER_SPAWN;
        static const std::string ANSWER_UP_VIRUS_SPREAD_CHANCE;

        static std::string getAssociatedText(DialogType dt);
        static std::string getAssociatedText(DialogAnswers da);
};

#endif