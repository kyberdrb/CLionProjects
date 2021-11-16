#pragma once

#include <memory>
#include <sstream>

namespace store {
    namespace electronics {
        namespace gaming {
            class NamespacedComputer {
                std::string id;
                static uint32_t sequenceId;
            public:
                NamespacedComputer() {
                    std::stringstream ss;
                    ss << sequenceId++;
                    id = ss.str();
                }

                explicit NamespacedComputer(std::string id) : id(std::move(id)) {}

                ~NamespacedComputer() {
                    std::cout << "NamespacedComputer deleted:\t" << id << std::endl;
                }
            };

            uint32_t NamespacedComputer::sequenceId = 0;

            using NamespacedComputerConstPtr = std::unique_ptr<const NamespacedComputer, void(*)(const NamespacedComputer*)>;
            void deleteNamespacedComputer(const NamespacedComputer* computer) {
                delete computer;
            }
            void doNotDeleteNamespacedComputer(const NamespacedComputer* computer);
        }
    }
}