#ifndef STATS_H
#define STATS_H

#include "Storage.h"

class Stats{
private:
    int _totalPackagesImported = 0;
    int _totalImportPrice = 0;

    int _totalPackagesExported = 0;
    int _totalIdealExportPrice = 0; // vpc
    int _totalRealExportPrice = 0; // vpc minus loss from delivery delay

    int _totalProfitDeliveries = 0;
    int _totalLossDeliveries = 0;

    int _totalOvernightPackages = 0; // packages that haven't been exported/delivered on the day of import
    int _totalNeverDeliveredPackages = 0;
public:
    Stats();
    void display(Storage storage);
};

#endif