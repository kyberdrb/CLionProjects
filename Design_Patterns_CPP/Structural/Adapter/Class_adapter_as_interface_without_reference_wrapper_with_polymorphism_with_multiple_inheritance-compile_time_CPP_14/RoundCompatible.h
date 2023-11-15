//
// Created by laptop on 11/12/23.
//

#pragma once

// Adapter Interface: common functionality shared between the Target class and the Adapter class
class RoundCompatible {
public:
    virtual double getRadius() const = 0;
};
