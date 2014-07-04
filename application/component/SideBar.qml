import QtQuick 2.0

Rectangle {
    id: sidebar

    
    function toggleshow() {
        if(sidebar.opacity == 0){
            sidebar.opacity = 1;
        }else{
            sidebar.opacity = 0;
        }
    }

    opacity: 0

    onOpacityChanged:{
        if(sidebar.opacity < 1){
            sidebar.enabled = false;
        }else if (sidebar.opacity == 1){
            sidebar.enabled = true;
        }   
    }

    Behavior on opacity {
        NumberAnimation { duration: 1000 }
    }

}
