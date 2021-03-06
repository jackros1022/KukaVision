// <KinectAcquisition> CLASS METHODS IMPLEMENTATION

#include <iostream>

#include <pcl/common/common.h>
#include <pcl/console/print.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include "KinectAcquisition.h"
#include "KinectAcquisitionViewer.h"

// CONSTRUCTOR
KinectAcquisition::KinectAcquisition() {}

// DESTRUCTOR
KinectAcquisition::~KinectAcquisition() {}

// #################################################################################################################################################################
// ACQUIRING CLOUD FROM KINECT #####################################################################################################################################
// #################################################################################################################################################################

void 
KinectAcquisition::AcquireCloudKinect(pcl::PointCloud<pcl::PointXYZ>::Ptr input_cloud)

{
	  // The function instantiate a <KinectAcquisitionViewer> class that starts the OpenNI grabber and a <pcl_visualizer> object. When the visualizer is closed, the 
	  // actual cloud is stored in <point_cloud>. 

	  // Acquisition viewer class instantiation
  	KinectAcquisitionViewer acquire;

    std::cout << "\tAcquiring the cloud ...\n" << std::flush;
  
  	// Acquiring function running
  	acquire.run ();
  	// Store the acquired cloud in the member <point_cloud> of the class
  	pcl::copyPointCloud(acquire.acquired_cloud,*input_cloud);

  	std::cout << "\t(" << acquire.acquired_cloud.points.size() << " points)" << std::endl;
}