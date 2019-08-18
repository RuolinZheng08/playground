//
//  controller.h
//  motivate
//
//  Created by Ruolin Zheng on 2019/8/18.
//  Copyright © 2019 Ruolin Zheng. All rights reserved.
//

#ifndef controller_h
#define controller_h

#include "model.hpp"
#include "view.hpp"

class MyApp: public wxApp {
public:
    virtual bool OnInit();
private:
    MyModel *model;
    MyView *view;
};

#endif /* controller_h */
