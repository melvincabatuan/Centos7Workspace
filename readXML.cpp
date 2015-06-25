#include "opencv2/opencv.hpp"
#include <fstream>

using namespace cv;
using std::cout;
using std::endl;
using std::vector;

  enum { MAX_FACES = 10000 };
  enum { BOOST = 0 };
  enum { DO_CANNY_PRUNING    = CASCADE_DO_CANNY_PRUNING,
        SCALE_IMAGE         = CASCADE_SCALE_IMAGE,
        FIND_BIGGEST_OBJECT = CASCADE_FIND_BIGGEST_OBJECT,
        DO_ROUGH_SEARCH     = CASCADE_DO_ROUGH_SEARCH
    };



class Data
    {
    public:
        struct DTreeNode
        {
            int featureIdx;
            float threshold; // for ordered features only
            int left;
            int right;
        };

        struct DTree
        {
            int nodeCount;
        };

        struct Stage
        {
            int first;
            int ntrees;
            float threshold;
        };

        struct Stump
        {
            Stump() { }
            Stump(int _featureIdx, float _threshold, float _left, float _right)
            : featureIdx(_featureIdx), threshold(_threshold), left(_left), right(_right) {}

            int featureIdx;
            float threshold;
            float left;
            float right;
        };
    };

       



int main()
{
        static const float THRESHOLD_EPS = 1e-5f;
        //Data();
        int stageType;
        int featureType;
        int ncategories;
        int minNodesPerTree, maxNodesPerTree;
        Size origWinSize;

        std::vector<Data::Stage> stages;
        std::vector<Data::DTree> classifiers;
        std::vector<Data::DTreeNode> nodes;
        std::vector<float> leaves;
        std::vector<int> subsets;
        std::vector<Data::Stump> stumps;


    std::cout<< endl << "Reading:" << endl;
    FileStorage fs;
    fs.open("lbpcascade_frontalface.xml", FileStorage::READ);

    if (!fs.isOpened()) 
    {
       cout<<"ERROR: Cannot open the xml file.\n";  
       return (-1);
    }

    cout<<"File is successfully opened\n";

    stageType = (int)fs["stageType"];
    cout << "stageType = " << stageType <<endl;

    featureType = (int)fs["featureType"];
    cout << "featureType = " << featureType <<endl;

     int height = (int)fs["height"];
    cout << "height = " << height <<endl;

     int width = (int)fs["width"];
     cout << "width = " << width <<endl;

    fs.release();
    return (0);
}
