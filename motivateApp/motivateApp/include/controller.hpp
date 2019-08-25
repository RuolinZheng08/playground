//
//  controller.hpp
//  motivateApp
//
//  Created by Ruolin Zheng on 2019/8/23.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#ifndef controller_hpp
#define controller_hpp

#include <stdio.h>
#include "model.hpp"
#include "view.hpp"

class MyApp: public wxApp {
public:
    MyModel *mModel;
    MyView *mView;
    
    virtual bool OnInit();
};

#endif /* controller_hpp */
