#include "Wave.h"

void Wave::Start(Storage& storage, Import& import, std::vector<Export&>& exports, Stats& stats){
    import.importNewPackages(storage);

    // TODO: replace with foreach loop
    for (int i = 0; i < exports.size(); i++){
        Export& currentExport = exports.at(i);
        for (int i = 0; i < storage.getNumStacks(); i++){
            Package topPackage = storage.getNthStack(i).getTop();
            int maxPackageWeight = currentExport.getMaxCapacity() - currentExport.getCurrentLoad();
            
            if (topPackage.getMass() <= maxPackageWeight){
                currentExport.addToLoad(topPackage);
            }
        }
    }
}