class Rectangle{

 protected:

  int left;
  int right;
  int top;
  int bot;

 public:

   //default value
    Rectangle(const int left = 0, const int right = 0, 
              const int top = 0, const int bot = 0);
    //getters
    int getLeft();
    int getRight();
    int getTop();
    int getBot();
    int getWidth(int left, int right);
    int getHeight(int top, int bot);
    //setters
    void setLeft(int left);
    void setRight(int right);
    void setTop(int top);
    void setBot(int bot);
    //other methods
    bool contains(int x, int y);
    bool intersects(const Rectangle());

};


