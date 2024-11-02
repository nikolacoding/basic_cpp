#include "Simulation.h"
#include <vector>

void Simulation::Test(){
    PackageStack st;
    Package p1, p2, p3;

    st.push(p1);
    st.push(p2);
    st.push(p3);

    bool valid;

    for (int i = 0; i < 3; i++){
        Package p = st.pop(valid);
        p.debugLog();
    }
}

void Simulation::Start(){
    Storage storage(-1000, 1000, 4);
    Import import(3, 50, 50);

    Export exp1("Jovan");
    Export exp2("Zoran");
    Export exp3("Goran");
    Export exp4("Ivan");
    Export exp5("David");

    std::vector<Export> exports;
    exports.push_back(exp1);
    exports.push_back(exp2);
    exports.push_back(exp3);
    exports.push_back(exp4);
    exports.push_back(exp5);

    Stats stats;

    // wave logika ovdje pocinje
    import.importNewPackages(storage);
    // TODO: provjera vrhovnih elementova steka od strane svakog clana exports
}

void Simulation::End(){
    
}