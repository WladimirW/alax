using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using DirectShowLib;
using AlaxInfoIpVideoSource;

namespace PlayJpegLocationSharp
{
    class Program
    {
        [STAThread]
        static void Main(string[] args)
        {
            FilterGraph filterGraph = new FilterGraph();
            IJpegVideoSourceFilter sourceFilter = new JpegVideoSourceFilter() as IJpegVideoSourceFilter;
            IBaseFilter sourceBaseFilter = sourceFilter as IBaseFilter;
            (filterGraph as IFilterGraph2).AddFilter(sourceBaseFilter, "Source");
            sourceFilter.Location = @"http://192.168.88.21/nph-mjpeg.cgi";
            sourceFilter.Width = 800;
            sourceFilter.Height = 448;
            IPin pin = DsFindPin.ByDirection(sourceBaseFilter, PinDirection.Output, 0);
            (filterGraph as IFilterGraph2).Render(pin);
            (filterGraph as IMediaControl).Run();
            EventCode eventCode;
            (filterGraph as IMediaEvent).WaitForCompletion(-1, out eventCode);
        }
    }
}
