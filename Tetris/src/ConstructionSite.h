#pragma once

class ConstructionSite {
public:
    const char16_t FLOOR = u'‾'; // OVERLINE

    ConstructionSite() = default;

    void showFirstStep();
    void showSecondStep();
    void showFinalStep();
};
