//
// Created by laptop on 4/17/23.
//

#pragma once

namespace production {
    enum class TransitionType {
        NONE,
        PUBLISH,
        RETURN_DOC_AFTER_REVIEW,
        EXPIRE
    };
}
