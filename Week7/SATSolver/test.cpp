#include<iostream>
#include"SATsolver.h"
using namespace std;

int main () {
    SATSolver s;
    Variable a;
    a.Name("a");
    Variable b;
    b.Name("b");
    auto f1 = make_shared<Formula>(a);
    auto f2 = make_shared<Formula>(b);
    auto andTest = Formula::And(f1,f2);
    auto orTest = Formula::Or(f1,f2);
    auto ifTest = Formula::If(f1,f2);
    auto iffTest = Formula::Iff(f1,f2);
    auto notTest = Formula::Not(f1);
    auto combineTest = Formula::And(Formula::Not(iffTest),Formula::Or(andTest,orTest));
    cout<<"Testing "<<andTest->toString()<<", should be SAT\n";
    s.add(andTest);
    s.solve();    
    cout<<s.result<<"\n";
    s.printModel();
    s.reset();
    cout<<"Testing "<<orTest->toString()<<", should be SAT\n";
    s.add(orTest);
    s.solve();    
    cout<<s.result<<"\n";
    s.printModel();
    s.reset();    
    cout<<"Testing "<<ifTest->toString()<<", should be SAT\n";
    s.add(ifTest);
    s.solve();    
    cout<<s.result<<"\n";
    s.printModel();
    s.reset();    
    cout<<"Testing "<<iffTest->toString()<<", should be SAT\n";
    s.add(iffTest);
    s.solve();    
    cout<<s.result<<"\n";
    s.printModel();
    s.reset();    
    cout<<"Testing "<<notTest->toString()<<", should be SAT\n";
    s.add(notTest);
    s.solve();    
    cout<<s.result<<"\n";
    s.printModel();
    s.reset();    
    cout<<"Testing "<<combineTest->toString()<<", should be SAT\n";
    s.add(combineTest);
    s.solve();    
    cout<<s.result<<"\n";
    s.printModel();
    s.reset();    
}