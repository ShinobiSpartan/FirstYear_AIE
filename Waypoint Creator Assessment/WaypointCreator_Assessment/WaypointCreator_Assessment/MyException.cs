﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WaypointCreator_Assessment
{
    class MyException : Exception
    {
        public override string Message
        {
            get
            {
                return "Please select a Text Box before trying to Copy and Paste.";
            }
        }
    }
}
