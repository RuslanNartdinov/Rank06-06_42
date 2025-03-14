#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
private:
    std::string ideas[100];

public:
    Brain();
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);
    ~Brain();

    // Доп. метод для примера, чтобы записать / вывести идеи
    void setIdea(int index, const std::string &idea);
    const std::string &getIdea(int index) const;
};

#endif