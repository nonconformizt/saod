#include <iostream>
#include "graph.cpp"

int main() 
{
    auto exp = new Experiment(4);
    
    exp->addEffect(0, "edge", 1); 
    exp->addEffect(1, "reverse", 0); 
    exp->addEffect(0, "smth", 3); 
    exp->addEffect(2, "quant", 0); 
    exp->addEffect(0, "antiquant", 2); 
    exp->addEffect(2, "twoone", 1); 
    exp->addEffect(1, "eff1", 3); 
    exp->addEffect(1, "eff2", 3); 
    exp->addEffect(1, "eff3", 3); 

    exp->findChains(2, 3);

}