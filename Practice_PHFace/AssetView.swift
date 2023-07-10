//
//  AssetView.swift
//  Practice_PHFace
//
//  Created by Jinwoo Kim on 7/10/23.
//

import SwiftUI
import PhotosUI

struct AssetView: View {
    private let phAsset: PHAsset
    @Environment(\.dismiss) private var dismiss: DismissAction
    @State private var image: UIImage?
    @State private var requestID: PHImageRequestID?
    @State private var isPresentingFacesView: Bool = false
    
    init(phAsset: PHAsset) {
        self.phAsset = phAsset
        loadImage()
    }
    
    var body: some View {
        VStack {
            if let image: UIImage {
                Image(uiImage: image)
                    .resizable()
                    .aspectRatio(contentMode: .fit)
            } else {
                ProgressView()
                    .progressViewStyle(.circular)
            }
        }
        .onAppear(perform: {
            loadImage()
        })
        .onDisappear {
            if let requestID: PHImageRequestID {
                PHImageManager.default().cancelImageRequest(requestID)
            }
        }
        .onChange(of: phAsset) { newValue in
            loadImage()
        }
        .toolbar {
            ToolbarItem(placement: .topBarLeading) { 
                Button("Faces") { 
                    isPresentingFacesView = true
                }
            }
            
            ToolbarItem(placement: .topBarTrailing) { 
                Button("Dismiss") {
                    dismiss()
                }
            }
        }
        .sheet(isPresented: $isPresentingFacesView) {
            NavigationStack { 
                FacesView(asset: phAsset)
            }
        }
    }
    
    private func loadImage() {
        self.image = nil
        
        if let requestID: PHImageRequestID {
            PHImageManager.default().cancelImageRequest(requestID)
        }
        
        let requestOption: PHImageRequestOptions = .init()
        requestOption.isNetworkAccessAllowed = true
        requestOption.isSynchronous = false
        
        let requestID: PHImageRequestID = PHImageManager
            .default()
            .requestImage(
                for: phAsset,
                targetSize: .init(width: phAsset.pixelWidth, height: phAsset.pixelHeight),
                contentMode: .default,
                options: requestOption
            ) { image, userInfo in
                guard let image: UIImage else {
                    return
                }
                
                Task { @MainActor in
                    self.image = image
                }
            }
        
        self.requestID = requestID
    }
}
