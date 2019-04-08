from conans import ConanFile, CMake, tools


class LibConan(ConanFile):
    requires = "GoogleTest/1.8.0@foundry/staging"
    generators = "cmake"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
