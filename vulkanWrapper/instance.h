#pragma once

#include "../include/base.h"

namespace FF::Wrapper {
    class Instance {
    public:
        Instance();
        virtual  ~Instance();
        using Ptr = std::shared_ptr<Instance>;
        static Ptr create() {
          return std::make_shared<Instance>();
        }

     private:
        VkInstance *instance_{nullptr};
    };
}