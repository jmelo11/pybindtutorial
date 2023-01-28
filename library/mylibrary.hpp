#ifndef D3C623E9_FC36_4EEF_9ED6_46B293F1B764
#define D3C623E9_FC36_4EEF_9ED6_46B293F1B764

/*
 * Created on Fri Jan 27 2023
 *
 * Copyright (c) 2023 Jose Melo
 */

#include <map>

namespace FinLib {

    using Date = double;

    /***
     * @brief Cashflows: A map of dates and cashflows
     */
    using Cashflows = std::map<Date, double>;

    enum Frequency { Monthly, Quarterly, Semiannual, Annual, Once };

    /***
     * @brief Bond: A bond is a fixed income security.
     *
     */
    class Bond {
       public:
        Bond(Date startDate, Date endDate, Frequency paymentFrequency, double notional, double couponRate);

        Cashflows cashflows() const;

       private:
        Date startDate_;
        Date endDate_;
        Frequency paymentFrequency_;
        double notional_;
        double couponRate_;
        Cashflows cashflows_;
    };

    /***
     * @brief Deposit: A deposit is a fixed income security. Inherited from Bond.
     *
     */
    class Deposit : public Bond {
       public:
        Deposit(Date startDate, Date endDate, double notional, double rate);
    };

    /***
     * @brief Calculates the present value of a set of cashflows
     *
     * @param cashflows
     * @param discountRate
     * @return double
     */

    inline double pv(const Cashflows& cashflows, double discountRate) {
        double pv = 0;
        for (auto& cf : cashflows) { pv += cf.second / (1 + discountRate * cf.first); }
        return pv;
    }

    /***
     * @brief Calculates the present value of a bond
     *
     * @param bond
     * @param discountRate
     * @return double
     */
    inline double pv(const Bond& bond, double discountRate) {
        return pv(bond.cashflows(), discountRate);
    }

};  // namespace FinLib

#endif /* D3C623E9_FC36_4EEF_9ED6_46B293F1B764 */
