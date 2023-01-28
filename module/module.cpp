#include "../library/mylibrary.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

PYBIND11_MODULE(FinLib, m) {
    m.doc() = "Financial Library";

    // Expose enums
    py::enum_<FinLib::Frequency>(m, "Frequency")
        .value("Monthly", FinLib::Frequency::Monthly)
        .value("Quarterly", FinLib::Frequency::Quarterly)
        .value("Semiannual", FinLib::Frequency::Semiannual)
        .value("Annual", FinLib::Frequency::Annual)
        .value("Once", FinLib::Frequency::Once)
        .export_values();

    // Expose classes
    py::class_<FinLib::Cashflows>(m, "Cashflows").def(py::init<>());

    py::class_<FinLib::Bond>(m, "Bond")
        .def(py::init<FinLib::Date, FinLib::Date, FinLib::Frequency, double, double>())
        .def("cashflows", &FinLib::Bond::cashflows);

    py::class_<FinLib::Deposit, FinLib::Bond>(m, "Deposit").def(py::init<FinLib::Date, FinLib::Date, double, double>());

    // Expose functions
    m.def("cashflowPV", py::overload_cast<const FinLib::Cashflows&, double>(&FinLib::pv), "Calculates the present value of a set of cashflows");
    m.def("bondPV", py::overload_cast<const FinLib::Bond&, double>(&FinLib::pv), "Calculates the present value of a bond");
}