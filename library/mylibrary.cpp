/*
 * Created on Fri Jan 27 2023
 *
 * Copyright (c) 2023 Jose Melo
 */

#include "mylibrary.hpp"

namespace FinLib {

    Bond::Bond(Date startDate, Date endDate, Frequency paymentFrequency, double notional, double couponRate)
    : startDate_(startDate), endDate_(endDate), paymentFrequency_(paymentFrequency), notional_(notional), couponRate_(couponRate) {
        // small sanity check
        if (startDate_ >= endDate_) { throw std::invalid_argument("Start date must be before end date"); }

        double yf;
        switch (paymentFrequency_) {
            case Monthly:
                yf = 1.0 / 12.0;
                break;
            case Quarterly:
                yf = 3.0 / 12.0;
                break;
            case Semiannual:
                yf = 0.5;
                break;
            case Annual:
                yf = 1;
                break;
            case Once:
                yf = endDate_ - startDate_;
                break;
            default:
                throw std::invalid_argument("Invalid payment frequency");
        }

        Date date = startDate_ + yf;
        while (date <= endDate_) {
            if (date == endDate_) {
                cashflows_[date] = notional_ + notional_ * couponRate_ * yf;
            } else {
                cashflows_[date] = notional_ * couponRate_ * yf;
            }
            date += yf;
        }
    }

    Cashflows Bond::cashflows() const {
        return cashflows_;
    }

    Deposit::Deposit(Date startDate, Date endDate, double notional, double rate) : Bond(startDate, endDate, Frequency::Once, notional, 0) {}

}  // namespace FinLib
