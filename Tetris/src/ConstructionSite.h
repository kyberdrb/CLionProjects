#pragma once

#include <string>

class ConstructionSite {
public:
    std::string playground[2][2] = {
            {"0", "1"}, {"4", "5"}
    };

    const char16_t FLOOR = u'‾'; // OVERLINE

    ConstructionSite() = default;

    void showFirstStep();
    void showSecondStep();
    void showFinalStep();

    std::string getCurrentPlayground() const;
};
