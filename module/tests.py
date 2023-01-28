import FinLib


def main():

    # date in years
    startDate = 0
    endDate = 5

    rate = 0.03
    notional = 100
    frequency = FinLib.Semiannual

    bond = FinLib.Bond(startDate, endDate, frequency, notional, rate)

    for date, cashflow  in bond.cashflows().items():     
        print('Date:\t{d},  Cashflow:\t{c}'.format(d=date, c=cashflow))


if __name__ == '__main__':
    main()
