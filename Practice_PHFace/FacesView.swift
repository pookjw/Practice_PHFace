//
//  FacesView.swift
//  Practice_PHFace
//
//  Created by Jinwoo Kim on 7/10/23.
//

import SwiftUI
import PhotosUI

struct FacesView: View {
    private let faces: [PHFace]
    @Environment(\.dismiss) private var dismiss: DismissAction
    
    init(faces: [PHFace]) {
        self.faces = faces
    }
    
    init(asset: PHAsset) {
        let fetchedPHFaces: PHFetchResult<PHFace> = PHFace.fetchFaces(inAsset: asset, options: nil) as! PHFetchResult<PHFace>
        var faces: [PHFace] = .init()
        fetchedPHFaces.enumerateObjects { face, _, _ in
            faces.append(face)
        }
        self.faces = faces
    }
    
    var body: some View {
        List(faces, id: \.self) { face in
            Text(face._fd_ivarDescription())
        }
        .toolbar {
            ToolbarItem(placement: .topBarTrailing) { 
                Button("Dismiss") {
                    dismiss()
                }
            }
        }
    }
}

#Preview {
    FacesView(faces: [])
}
