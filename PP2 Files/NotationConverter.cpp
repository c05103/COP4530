#include "NotationConverter.hpp"
#include "LinkedList.hpp"

NotationConverter::NotationConverter(){
    LinkedList();
}

//Inserts element to the front of the deque
void NotationConverter::insertFront(const Elem& e){
    element.addFront(e);
    num ++;
}

//Inserts element to the end of the deque
void NotationConverter::insertBack(const Elem& e){
    element.addBack(e);
    num ++;
}

//Returns if deque is empty
bool NotationConverter::empty() const{
    return element.empty();
}

//Returns the size of the deque
int NotationConverter::size() const{
    return num;
}

//Removes element from the front of the deque
void NotationConverter::removeFront(){
    if(empty())
        throw ("DequeEmpty");
    
    else{
        element.removeFront();
        num --;
    }
}

//Removes element from the back of the deque
void NotationConverter::removeBack(){
    if(empty())
        throw("DequemEmpty");
    
    else {
        element.removeBack();
        num --;
    }
}

//Helper function to test if it's an operand
bool NotationConverter::isOperator(char ex){
    switch(ex){
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
    }
    return false;
}

std::string NotationConverter::postfixToInfix(std::string inStr){
    std::regex self_regex("[a-zA-Z +-/*()]+");
    string character = " ";
    string temp = " ";

//Regex to ensure input validation
    if(regex_match(inStr, self_regex) == false){
        throw("Invalid String");
    }

    for (char i = 0; i < inStr.length(); i++){
        if(isOperator(i)){
            character += i;
            element.addBack(character);
            character = " ";
        }

        else 
            temp += i;

    }


    // for (char i = 0; i < inStr.length(); i ++){
    //     if(i == '+'|| i == '*' || i == '/' || i == '-'){
    //         element.addBack(i);
    //     }

    //     else{
    //         temp.append(i);
    //         element.removeBack();


    //     }
    // }

    else
        return inStr;
}

std::string NotationConverter::postfixToPrefix(std::string inStr){

    stringstream word;
    word << inStr;

    return word.str();
}

std::string NotationConverter::infixToPostfix(std::string inStr){
    return inStr;
}

std::string NotationConverter::infixToPrefix(std::string inStr){
    return inStr;
}

std::string NotationConverter::prefixToInfix(std::string inStr){
    return inStr;
}

std::string NotationConverter::prefixToPostfix(std::string inStr){
    return inStr;
}


