
function loading(parent) {
    var ls = [];
    var component = Qt.createComponent("Loading.qml");
    for (var i=0; i<20; i++) {
        var object = component.createObject(parent);
        object.pwidth = parent.width + (i - 10) * 20;
        object.x = object.pwidth + (i - 10) * 20;
        object.y = parent.height/2;
        ls[i] = object;
    }
    return ls;
}

function loadingfinish(ls){
    if(ls){
        for(var i=0, len=ls.length; i < len; i++){
            if(ls[i]){
                if(ls[i].hasOwnProperty('destroy')){
                    ls[i].destroy();
                }
            }
        }
    }
    ls = [];
    return ls;
}