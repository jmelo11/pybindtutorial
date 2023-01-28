from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup
from pathlib import Path

__version__ = "1.0.0"

libraryName = "FinLib"
LIBDIR = (Path(__file__).parent.parent / "library").resolve()  # Path to the library

ext_modules = [
    Pybind11Extension(libraryName,
                      ["module.cpp"],
                      include_dirs=[str(LIBDIR)],
                      library_dirs=[str(LIBDIR / "build")],
                      libraries=[libraryName],
                      define_macros=[('VERSION_INFO', __version__)],
                      language="c++20"
                      ),
]

setup(
    name=libraryName,
    version=__version__,
    author="Jose Melo",
    author_email="jmelo@live.cl",
    description="FinLib using pybind11",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    python_requires=">=3.7",
)
