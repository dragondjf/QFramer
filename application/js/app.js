
function showWindow(){
    if(mainwindow.isfullscreen == true)
        {
            mainwindow.showNormal();
            mainwindow.isfullscreen = false;
        }
    else{
        mainwindow.showFullScreen();
        mainwindow.isfullscreen = true;         
    }
}

function showFullScreen(){
    mainwindow.width = Screen.desktopAvailableWidth
    mainwindow.height = Screen.desktopAvailableHeight
}


function showNormal(){
    mainwindow.width = Screen.desktopAvailableWidth * 0.8
    mainwindow.height = Screen.desktopAvailableHeight * 0.8
}