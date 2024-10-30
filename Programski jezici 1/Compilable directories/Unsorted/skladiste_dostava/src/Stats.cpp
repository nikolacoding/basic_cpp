#include "Stats.h"
#include <iostream>

Stats::Stats(){

}

void Stats::display(Storage storage){
    using std::cout;
    using std::endl;

    cout << "Total packages imported: " << this->_totalPackagesImported <<
        " for the price of " << this->_totalImportPrice << endl;

    int delayDifference = this->_totalIdealExportPrice - this->_totalRealExportPrice;
    cout << "Total packages exported: " << this->_totalPackagesExported <<
        " for the price of " << this->_totalRealExportPrice << ", would've ideally been " << 
        this->_totalIdealExportPrice << " if not for late deliveries costing us " << 
        delayDifference << "!" << endl;

    cout << "In total, we made " << this->_totalProfitDeliveries << " profitable deliveries." << endl;
    cout << "However we lost money on another " << this->_totalLossDeliveries << "deliveries..." << endl;

    cout << "The number of packets that spent a night or longer waiting to be delivered is " << 
    this->_totalOvernightPackages << ", with another " << this->_totalNeverDeliveredPackages << 
    " that never saw their recipient due to excessive delay." << endl;

    cout << "In general, we made " << _totalRealExportPrice;
    if (storage._netCurrent < storage._maxLoss){
        cout << " but it wasn't enough to offset our net loss of " << storage._netCurrent << ", leading " <<
        " our storage to no other choice but to ceise existence as we crossed our allowed loss " << 
        " overhead of " << storage._maxLoss << "." << endl;
    }
    else{
        cout << " and with our net total of " << storage._netCurrent << ", we have finally guaranteed ourselves" <<
        " enough funds to safely move to a bigger location and scale up our operations, since we crossed " <<
        "our goal of "  << storage._maxProfit << "!" << endl;
    }
}