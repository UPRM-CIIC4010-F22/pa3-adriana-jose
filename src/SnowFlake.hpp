#pragma once

#include "ofMain.h"
#include <cmath>
#include "AbstractFractal.hpp"

/**
 * @brief Koch SnowFlake Fractal
 *
 */

class SnowFlake : public AbstractFractal {
  private:
    glm::vec2 start;
    glm::vec2 end;
    string name = "Koch Snowflake";
    int level = 5;

  public:
    SnowFlake();
    SnowFlake(glm::vec2 start, glm::vec2 end);

    glm::vec2 getStart() const { return start; }
    glm::vec2 getEnd() const { return end; }
    void setStart(glm::vec2 start) { this->start = start; }
    void setEnd(glm::vec2 end) { this->end = end; }

    void draw(); //added variable
    void draw(int level, SnowFlake *flake);

    void setLevel(int l){level = l;}
    int getLevel(){return level;}

    void setName(string n){name = n;}
    string getName(){return name;}

    glm::vec2 getA();
    glm::vec2 getB();
    glm::vec2 getC();
    glm::vec2 getD();
    glm::vec2 getE();
};